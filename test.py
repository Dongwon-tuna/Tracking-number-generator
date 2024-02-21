import qrcode
from PIL import Image, ImageDraw, ImageFont
import json


json_file_path = 'trackingdata.json'


with open(json_file_path, 'r') as json_file:

    data = json.load(json_file)

tracking_number = '34413666d32125731102'


qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)
qr.add_data(tracking_number)
qr.make(fit=True)

qr_code = qr.make_image(fill_color="black", back_color="white")
qr_path = f"{tracking_number}_qr.png"
qr_code.save(qr_path)


width, height = 500, 300

image = Image.new("RGB", (width, height), "white")
draw = ImageDraw.Draw(image)

font = ImageFont.load_default()
font_size = 30

receiver_info = "Receiver"
sender_info = "Shipper"
customer_request_text = "Customer's Request"

draw.text((40, 14), f"Tracking Number: {tracking_number}", fill="black", font=font)
draw.text((40, 60), f"봉정로 365: {tracking_number}", fill="black", font=font)
draw.text((150, 90), sender_info, fill="black", font=font)
draw.text((150, 130), receiver_info, fill="black", font=font)



qr_img = Image.open(qr_path)
qr_width, qr_height = qr_img.size
desired_qr_height = 100  
desired_qr_width = int(qr_width * (desired_qr_height / qr_height))
qr_img = qr_img.resize((desired_qr_width, desired_qr_height))
image.paste(qr_img, (30, 70))
draw.text((40, 190), customer_request_text, fill="black", font=font)

image.save("shipping_label_with_qr.png")


image.show()
