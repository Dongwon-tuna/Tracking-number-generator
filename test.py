import qrcode
from barcode import Code128
from barcode.writer import ImageWriter
import json

myQR = qrcode.make("https://www.youtube.com/")
myQR.save("newQR.png")

number = '34413666d32125731102'

my_code = Code128(number,writer=ImageWriter())
my_code.save(number)

with open('C:\\test.json', 'r') as f:

    json_data = json.load(f)

print(json.dumps(json_data) )