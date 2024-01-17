# pdf: 
# 	platex sample.tex
# 	dvipdfmx sample.dvi
pdf:
	platex sample.tex
	dvipdfmx sample.dvi
	pdfjam --outfile sample_temp.pdf sample.pdf 2-
	pdfjam --outfile 西村昭治_1J20F037_奥村飛悠_卒研.pdf 表紙テンプレート.pdf sample_temp.pdf


count:
	bash wordcount_all_pdf.sh

.PHONY: pdf count