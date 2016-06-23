
rfe<-function(traindata,trainy)
{
  maxacc<-111111111111111111111
  p<-1:ncol(traindata)
  while(length(p)>3){
    si=as.integer(nrow(traindata)/2)
    index<-sample(1:nrow(traindata),size=si)
    train<-traindata[-index,p]
    try<-trainy[-index]
    test<-traindata[index,p]

    ty<-trainy[index]
    
    rf<-rfmode(train,try)
    pr<-rfpre(rf,test)
    
    cost1<-costvalue(pr,ty,test,config2,0) 
    
    train<-traindata[index,p]
    try<-trainy[index]
    test<-traindata[-index,p]
    ty<-trainy[-index]
    rf<-rfmode(train,try)
    pr<-rfpre(rf,test)
    cost2<-costvalue(pr,ty,test,config2,0)
    
    cost<-(cost1+cost2)/2
    
    
    print(cost)
    print(p)
    if(cost<maxacc){
      maxacc<-cost
      maxp<-p
    }
    im<-importance(rf)[1:length(p)-1]
    delete<-order(im)[length(im)]
    p<-p[-delete]
  }
  return(maxp)
  
}