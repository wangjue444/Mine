library(randomForest)

rfmode<-function(traindata,trainy)
{
  rfdata<-cbind(traindata,trainy)
  rfdata<-rfdata[,-1]
  rf<-randomForest(trainy~.,data=rfdata,importance=TRUE)
  return(rf)
}

rfpre<-function(mode,data)
{
  data<-data[,-1]
  pre<-predict(mode,data)
  return(pre)
}


xgbmode<-function(traindata,trainy)
{
  xgb<-xgboost(data=data.matrix(traindata[,-1]),label=trainy+0.0,nround=10,objective="reg:linear")
  return(xgb)
}

xgbpre<-function(mode,data)
{
  data<-data[,-1]
  pre<-predict(mode,data.matrix(data))
  return(pre)
}

svmmode<-function(traindata,trainy)
{
  svm.model<-svm(trainy~.,data=cbind(traindata[,-1],trainy))
  return(svm.model)
}

svmpre<-function(mode,data)
{
  data<-data[,-1]
  pre<-predict(mode,data)
  return(pre)
  
}