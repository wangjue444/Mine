package com.city.hospitalmanagement.dao;

import java.util.List;

import com.city.hospitalmanagement.value.LoginValue;

public interface ILoginDao {
	public void create(LoginValue lv) throws Exception;
	public void update(LoginValue lv) throws Exception;
	public void delete(LoginValue lv) throws Exception;
	public LoginValue get(String username) throws Exception;
	public List<LoginValue> getList() throws Exception;
}
