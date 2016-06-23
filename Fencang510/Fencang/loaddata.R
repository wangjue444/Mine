setwd("D:/Rproject/Fencang510_2/Fencang510/Fencang")
source("utils/extract.R")
source("utils/model.R")
source("utils/validation.R")
source("utils/Bench.R")


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

rf<-rfmode(traindata,trainy)
pr<-rfpre(rf,testdata)
cost<-costvalue(pr,testy,testdata,config2,0)

xgb<-xgbmode(traindata,trainy)
pr<-xgbpre(xgb,testdata)
cost<-costvalue(pr,testy,testdata,config2,0)

svm.model<-svmmode(traindata,trainy)
pr<-svmpre(svm.model,testdata)
cost<-costvalue(pr,testy,testdata,config2,0)


