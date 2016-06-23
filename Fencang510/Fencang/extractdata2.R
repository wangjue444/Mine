
#totally old data, both train and test. less item

data1831<-extract_by_date(item_feature2,20151018,20151031)
data0417<-extract_by_date(item_feature2,20151004,20151017)
data2003<-extract_by_date(item_feature2,20150920,20151003)


re<-make_dataset(data2003,data0417)

traindata<-re$dataset
trainy<-re$y

re<-make_dataset(data0417,data1831)
testdata<-re$dataset
testy<-re$y

bench<-makebench(traindata,trainy,testdata) #877043.2

rf<-rfmode(traindata,trainy)
pr<-rfpre(rf,testdata)
cost<-costvalue(pr,testy,testdata,config2,0)  #1171626