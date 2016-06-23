package com.city.hospitalmanagement.action;

import javax.mail.Authenticator;
import javax.mail.PasswordAuthentication;

public class MailAuth extends Authenticator{
	String userName=null;
	String password=null;
	public MailAuth(String userName,String password){
		this.userName=userName;
		this.password=password;
	}
	
	public PasswordAuthentication getPasswordAuthentication(){
		return new PasswordAuthentication(userName,password);
		
	}
}