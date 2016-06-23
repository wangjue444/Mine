
#exclude 1212 and 1111, maybe still some influence

data1427<-extract_by_date(item_feature2,20151214,20151227)
data111427<-extract_by_date(item_feature2,20151114,20151127)
data2810<-extract_by_date(item_feature2,20151128,20151210)


re<-make_dataset(data111427,data2810)

traindata<-re$dataset
trainy<-re$y

re<-make_dataset(data2810,data1427)
testdata<-re$dataset
testy<-re$y

bench<-makebench(traindata,trainy,testdata)  #1104952


rf<-rfmode(traindata,trainy)
pr<-rfpre(rf,testdata)
cost<-costvalue(pr,testy,testdata,config2,0) #1432773