import png

width = 1
height = 1
img = [0, 255, 0]
with open('out.png', 'wb') as f:
    w = png.Writer(width, height, greyscale=False)
    w.write(f, img)
