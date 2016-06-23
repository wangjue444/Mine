costvalue<-function(pre,testy,testdata,config,cang)
{
  
  if(cang==0){
    subconfig<-config[config[,2]=="all",]
    
  }else{
    subconfig<-config[config[,2]==cang,]
  }
  
  subconfig<-subconfig[order(subconfig[,1]),]
  testdata<-testdata[order(testdata[,1]),]
  itemid<-testdata[,1]
  #subconfig<-subconfig[is.element(subconfig[,1],itemid),]
  subconfig<-subconfig[match(itemid,subconfig[,1]),]
  if(!all(subconfig[,1]==itemid)){
    stop("in costvalue!")
  }
  
  shao<-testy-pre
  shao[shao<rep(0,length(shao))]<-0
  
  duo<-pre-testy
  duo[duo<rep(0,length(duo))]<-0
  
  
  cost<-sum(subconfig[,3]*shao + subconfig[,4]*duo)
  
}