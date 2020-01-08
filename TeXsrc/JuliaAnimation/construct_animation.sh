for i in {00001..960}; do convert $i.pgm $i.png; done
convert -delay 5 -loop 0 *.png animation.gif
