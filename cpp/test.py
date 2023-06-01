import jieba

txt=open("pyin.txt","r").read()
for i in "（）——=+~·-|、《》{}【】；：‘’“”，。？/":
    txt.replace(i,"")
print("【"in txt)
words=jieba.lcut(txt)
count={}
for word in words:
    count[word]=count.get(word,0)+1
ls=list(count.items())
ls.sort(key=lambda x:x[1],reverse=True)
print("{}:{}".format(ls[0][0],ls[0][1]))