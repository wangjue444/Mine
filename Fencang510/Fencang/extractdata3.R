
#old data, double train

data1831<-extract_by_date(item_feature2,20151018,20151031)
data0417<-extract_by_date(item_feature2,20151004,20151017)
data2003<-extract_by_date(item_feature2,20150920,20151003)
data0619<-extract_by_date(item_feature2,20150906,20150919)


re<-make_dataset(data2003,data0417)

traindata<-re$dataset
trainy<-re$y

re<-make_dataset(data0417,data1831)
testdata<-re$dataset
testy<-re$y


bench<-makebench(traindata,trainy,testdata) #877043.2



re<-make_dataset(data0619,data2003)
oldtraindata<-re$dataset
oldtrainy<-re$y

re<-combine_dataset(traindata,trainy,oldtraindata,oldtrainy)
traindata<-re$data
trainy<-re$y

rf<-rfmode(traindata,trainy)
pr<-rfpre(rf,testdata)
cost<-costvalue(pr,testy,testdata,config2,0)   #1055524