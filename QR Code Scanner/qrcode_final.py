from pyzbar import pyzbar
import numpy
import argparse
import cv2

ap=argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to input image")
args=vars(ap.parse_args())

image=cv2.imread(args["image"])

qrcodes=pyzbar.decode(image)

for qrcode in qrcodes:
    (x,y,w,h)=qrcode.rect
    cv2.rectangle(image,(x,y),(x+w,y+h),(0,0,255),2)

    qrcodeData=qrcode.data.decode("utf-8")
    qrcodeType=qrcode.type

    text="{} ({})".format(qrcodeData,qrcodeType)
    cv2.putText(image,text,(x,y-10),cv2.FONT_HERSHEY_SIMPLEX,0.5,(0,0,255),2)
cv2.imshow("Image",image)
cv2.waitKey(0)
