makebench<-function(traindata,trainy,testdata)
{
  ins<-intersect(unique(traindata[,1]),unique(testdata[,1]))
  feiling<-trainy[is.element(traindata[,1],ins)]
  pr<-rep(0,nrow(testdata))
  pr[is.element(testdata[,1],ins)]<-feiling
  return (pr)
  
  
}

