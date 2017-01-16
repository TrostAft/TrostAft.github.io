mrend=webtex
default: 
	pandoc -s --$(mrend) source.md -o index.html
	pandoc -s index.html --$(mrend) --css css/min_style.css -o index.html
	cp index.html min.html
