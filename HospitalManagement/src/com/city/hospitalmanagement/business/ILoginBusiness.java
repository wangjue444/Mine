package com.city.hospitalmanagement.business;

import com.city.hospitalmanagement.value.LoginValue;

public interface ILoginBusiness {
	public boolean check(String username,String password,String type) throws Exception;
	public void add(String username,String password,String type) throws Exception;
	public LoginValue get(String username) throws Exception;
	public void delete(String id) throws Exception;
}
