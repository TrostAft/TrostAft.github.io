default: 
	pandoc -s min.md -o index.html
	pandoc -s index.html --css CSS/min_style.css -o index.html
	cp index.html min.html
