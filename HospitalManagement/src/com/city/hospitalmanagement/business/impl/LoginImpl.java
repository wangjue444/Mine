package com.city.hospitalmanagement.business.impl;

import com.city.hospitalmanagement.business.ILoginBusiness;
import com.city.hospitalmanagement.dao.ILoginDao;
import com.city.hospitalmanagement.factory.DaoFactory;
import com.city.hospitalmanagement.value.LoginValue;

public class LoginImpl implements ILoginBusiness {

	@Override
	public boolean check(String username,String password,String type) throws Exception{
		
		ILoginDao ldo=DaoFactory.getLoginDao();
		
			LoginValue lv=ldo.get(username);
			if(lv==null){
				return false;
			}
			
			
			
			if(type.equals(lv.getType())&&password.equals(lv.getPassword())&&username.equals(lv.getUsername())){
		
				return true;
			}
			else{
				return false;
			}
		
	
		
	}

	@Override
	public void add(String username, String password, String type)
			throws Exception {
		ILoginDao ldo=DaoFactory.getLoginDao(); 
		LoginValue lv=new LoginValue();
		lv.setUsername(username);
		lv.setPassword(password);
		lv.setType(type);
	
		ldo.create(lv);
		
	
		
	}

	@Override
	public LoginValue get(String username) throws Exception {
		ILoginDao ldo=DaoFactory.getLoginDao();
		LoginValue lv=ldo.get(username);
		
		return lv;
	}

	@Override
	public void delete(String id) throws Exception {
		ILoginDao ldo=DaoFactory.getLoginDao();
		LoginValue lv=new LoginValue();
		lv.setUsername(id);
		ldo.delete(lv);
		
	}

}
