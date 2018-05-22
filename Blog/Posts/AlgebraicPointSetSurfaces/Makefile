mrend=mathjax
default: 
	pandoc -s --$(mrend) source.md -o APSS.html
	pandoc -s APSS.html --$(mrend) --css ./Resources/min_style.css -o temp.html
	mv temp.html APSS.html
