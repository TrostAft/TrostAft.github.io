default: 
	pandoc -s source.md -o index.html
	pandoc -s index.html --css css/min_style.css -o index.html
	cp index.html min.html
