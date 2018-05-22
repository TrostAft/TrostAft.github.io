mrend=webtex
default: 
	pandoc -s --$(mrend) source.md -o Blog.html
	pandoc -s Blog.html --$(mrend) --css ./Resources/min_style.css -o temp.html
	mv temp.html Blog.html
