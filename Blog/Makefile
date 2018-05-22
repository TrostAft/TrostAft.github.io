mrend=webtex
default: 
	pandoc -s --$(mrend) source.md -o Blog.html
	pandoc -s Blog.html --$(mrend) --css min_style.css -o temp.html
	mv temp.html Blog.html
