import Image
im=Image.open("vid.png")
im=im.resize((100,75),Image.ANTIALIAS)
im.save("vtemp.jpg")

