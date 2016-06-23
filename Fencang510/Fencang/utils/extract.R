extract_by_date<-function(data,low,high)
{
  
  extractdata<-data[(data[,1]<=high&data[,1]>=low),]
  by_feature<-extractdata[,2]
  subdata<-extractdata[,7:ncol(extractdata)]
  
  
  aggdata<-aggregate(subdata,by=list(by_feature),FUN=sum)
  
}

make_dataset<-function(databefore,dataafter)
{
  item<-intersect(unique(databefore[,1]),unique(dataafter[,1]))
  dataset<-databefore[is.element(databefore[,1],item),]
  datatest<-dataafter[is.element(dataafter[,1],item),]
  
  if(!all(dataset[,1]==datatest[,1])){
    stop("cuole!")
  }
  
  y<-datatest[,ncol(datatest)-1]
  re<-list()
  re$dataset<-dataset
  re$y<-y
  return(re)
}


subfeature<-function(traindata,deletefeature)
{
  traindata[,-deletefeature]
}


RangeScaling<-function(train,test)
{
  minvect<- apply(train[,-1], 2, min);
  rangevect<- apply(train[,-1], 2, function(x)diff(range(x))) 
  re<-list()
  re$scaletrain<-scale(train[,-1], center=minvect, scale=rangevect)
  re$scaletest<-scale(test[,-1], center=minvect, scale=rangevect)
  re$scaletrain<-cbind(train[,1],re$scaletrain)
  re$scaletest<-cbind(test[,1],re$scaletest)
  class(re)<-"ScalingRe"
  return(re)
}


make_feature<-function(feature,featurename)
{
  names(feature)<-featurename
  return (feature)
}


combine_dataset<-function(traindata,trainy,oldtraindata,oldtrainy)
{
  cdata<-rbind(traindata,oldtraindata)
  cy<-c(trainy,oldtrainy)
  re<-list()
  re$data<-cdata
  re$y<-cy
  return (re)
  
  
}
