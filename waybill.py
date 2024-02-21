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

width, height = 550, 300

# Create a white image
image = Image.new("RGB", (width, height), "white")
draw = ImageDraw.Draw(image)

# Draw a black border around the image
border_thickness = 1
draw.rectangle([0, 0, width - 1, height - 1], outline="black", width=border_thickness)

font_size = 18
font = ImageFont.load_default().font_variant(size=font_size)
font2 = ImageFont.load_default().font_variant(size=25)

receiver_info = "Receiver's information:"
sender_info = "Shipper's information:"
customer_request_text = "Customer's Request:"

draw.text((15, 18), f"Tracking Number: {tracking_number}", fill="black", font=font)
draw.text((15, 60), f"Address:", fill="black", font=font2)
draw.text((130, 110), sender_info, fill="black", font=font)
draw.text((130, 160), receiver_info, fill="black", font=font)

qr_img = Image.open(qr_path)
qr_width, qr_height = qr_img.size
desired_qr_height = 120  
desired_qr_width = int(qr_width * (desired_qr_height / qr_height))
qr_img = qr_img.resize((desired_qr_width, desired_qr_height))
image.paste(qr_img, (5, 90))
draw.text((15, 220), customer_request_text, fill="black", font=font)

image.save("shipping_label_with_qr.png")
image.show()
