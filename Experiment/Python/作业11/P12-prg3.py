import jieba
import matplotlib.pyplot as plt
from wordcloud import WordCloud, STOPWORDS, ImageColorGenerator

words = open("中国制造2025.txt", encoding = 'utf-8').read()
words = "".join(jieba.cut(words))

wordcloud = WordCloud(font_path = "simsun.ttf", background_color = "white", margin = 3).generate(words)

plt.imshow(wordcloud, interpolation = 'bilinear')
plt.axis("off")

plt.show()