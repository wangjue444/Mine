source("utils/extract.R")
source("utils/model.R")
source("utils/validation.R")
source("utils/Bench.R")
source("featureengine.R")
source("RFE.R")

library(data.table)
library(xgboost)
library(randomForest)
library(e1071)

item_feature2<-read.csv("data/item_feature2.csv",header=FALSE)
item_store_feature2<-read.csv("data/item_store_feature2.csv",header=FALSE)
config2<-read.csv("data/config2.csv",header=FALSE)
bushao<-as.numeric(unlist(tstrsplit(unlist(config2[3]),"_")[1]))
buduo<-as.numeric(unlist(tstrsplit(unlist(config2[3]),"_")[2]))
config2[,3]<-list(bushao)
config2[,4]<-list(buduo)


item_cat<-unique(item_feature2[,2:4])


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

re<-make_cat_feature(traindata,testdata)
traindata<-re$traindata
testdata<-re$testdata

maxp<-rfe(traindata,trainy)

subtrain<-traindata[,maxp]
subtest<-testdata[,maxp]


rf<-rfmode(subtrain,trainy)
pr<-rfpre(rf,subtest)
cost<-costvalue(pr,testy,subtest,config2,0) #1311503

print(cost)
print(maxp)
