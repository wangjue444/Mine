
#laterdate  double train
source("featureengine.R")



data1427<-extract_by_date(item_feature2,20151214,20151227)
data111427<-extract_by_date(item_feature2,20151114,20151127)
data2810<-extract_by_date(item_feature2,20151128,20151210)
data2709<-extract_by_date(item_feature2,20151027,20151109)

re<-make_dataset(data111427,data2810)

traindata<-re$dataset
trainy<-re$y

re<-make_dataset(data2810,data1427)
testdata<-re$dataset
testy<-re$y


bench<-makebench(traindata,trainy,testdata)  #1104952

re<-make_dataset(data2709,data111427)
oldtraindata<-re$dataset
oldtrainy<-re$y



re<-combine_dataset(traindata,trainy,oldtraindata,oldtrainy)
traindata<-re$data
trainy<-re$y



nname<-1:ncol(traindata)
cname<-unlist(lapply(nname,FUN=function(x){paste('V',x,sep="")}))
names(traindata)<-cname

re<-make_sub_feature(traindata,testdata)
traindata<-cbind(traindata,re$subtrainfeature)
testdata<-cbind(testdata,re$subtestfeature)


re<-make_cat_feature(traindata,testdata)
traindata<-re$traindata
testdata<-re$testdata



rf<-rfmode(traindata,trainy)
pr<-rfpre(rf,testdata)
cost<-costvalue(pr,testy,testdata,config2,0) #1311503

