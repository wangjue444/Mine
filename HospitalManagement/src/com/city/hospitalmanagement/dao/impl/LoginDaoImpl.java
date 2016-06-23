package com.city.hospitalmanagement.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.dao.ILoginDao;
import com.city.hospitalmanagement.factory.ConnectionFactory;

import com.city.hospitalmanagement.value.LoginValue;

public class LoginDaoImpl implements ILoginDao {

	@Override
	public void create(LoginValue lv) throws Exception {
		String sql="insert into Login values(?,?,?)";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, lv.getUsername());
			ps.setString(2, lv.getPassword());
			ps.setString(3, lv.getType());

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("登录Dao增加错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void update(LoginValue lv) throws Exception {
		String sql="update Login set password=?,type=? where username=?";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			
			ps.setString(1, lv.getPassword());
			ps.setString(2, lv.getType());
			ps.setString(3, lv.getUsername());

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("登录Dao更新错误"+e.getMessage());
		}
		finally{
			cn.close();
		}


	}

	@Override
	public void delete(LoginValue lv) throws Exception {
		String sql="delete from Login where username=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1,lv.getUsername());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("登录Dao删除错误"+e.getMessage());
		}
		finally{
			cn.close();
		}


	}

	@Override
	public LoginValue get(String username) throws Exception {
		LoginValue lv=null;
		String sql="select * from Login where username=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, username);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				lv=new LoginValue();
				lv.setUsername(rs.getString(1));
				lv.setPassword(rs.getString(2));
				lv.setType(rs.getString(3));
		
			
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("登录DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return lv;
	}
	
	

	@Override
	public List<LoginValue> getList() throws Exception {
		List<LoginValue> loginList=new ArrayList();
		String sql="select * from Login";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				LoginValue lv=new LoginValue();
				lv.setUsername(rs.getString(1));
				lv.setPassword(rs.getString(2));
				lv.setType(rs.getString(3));
				
				loginList.add(lv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("登录DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return loginList;
	}

}
