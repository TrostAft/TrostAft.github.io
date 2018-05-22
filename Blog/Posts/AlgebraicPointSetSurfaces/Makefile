name=texResult
PLatFlags= -jobname=$(name) --shell-escape

default:
	make build
	make build
	make clean

dirty:
	make build
	make build

build:
	pdflatex $(PLatFlags) main.tex

html:
	htlatex main.tex

htmlclean:
	mv main.tex temp.tex
	rm main*
	mv temp.tex main.tex

clean:
	rm $(name).log $(name).aux
	rm -rf _minted-*
