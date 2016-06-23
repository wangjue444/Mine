package com.city.hospitalmanagement.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.dao.IInfoDao;
import com.city.hospitalmanagement.factory.ConnectionFactory;
import com.city.hospitalmanagement.value.InfoValue;
import com.city.hospitalmanagement.value.LoginValue;

public class InfoDaoImpl implements IInfoDao {

	@Override
	public void create(InfoValue iv) throws Exception {
		String sql="insert into Info(name,age,tel,othertel,diseasetype,photo) values(?,?,?,?,?,?)";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, iv.getName());
			ps.setInt(2, iv.getAge());
			ps.setString(3, iv.getTel());
			ps.setString(4, iv.getOthertel());
			ps.setString(5, iv.getDiseasetype());
			ps.setString(6,iv.getPhoto() );

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("病人信息Dao增加错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void updtae(InfoValue iv) throws Exception {
		String sql="update  Info set name=?,age=?,tel=?,othertel=?,diseasetype=? where id=?";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, iv.getName());
			ps.setInt(2, iv.getAge());
			ps.setString(3, iv.getTel());
			ps.setString(4, iv.getOthertel());
			ps.setString(5, iv.getDiseasetype());
			ps.setInt(6,iv.getId());
			

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("病人信息Dao更新错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void delete(InfoValue iv) throws Exception {
		
		String sql="delete from Info where id=?";
		Connection cn=null;
		try{
			
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1,iv.getId());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("病人信息Dao删除错误"+e.getMessage());
		}
		finally{
			cn.close();
		}


	}

	@Override
	public InfoValue get(int id) throws Exception {
		InfoValue iv=null;
		String sql="select * from Info where id=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1,id );
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				iv=new InfoValue();
				iv.setId(rs.getInt("id"));
				iv.setName(rs.getString("name"));
				iv.setAge(rs.getInt("age"));
				iv.setTel(rs.getString("tel"));
				iv.setOthertel(rs.getString("othertel"));
				iv.setDiseasetype(rs.getString("diseasetype"));
				iv.setPhoto(rs.getString("photo"));
			
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("病人信息DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return iv;
	}

	@Override
	public List getList() throws Exception {
		List<InfoValue> infoList=new ArrayList();
		String sql="select * from Info";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				InfoValue iv=new InfoValue();
				iv.setId(rs.getInt("id"));
				iv.setName(rs.getString("name"));
				iv.setAge(rs.getInt("age"));
				iv.setTel(rs.getString("tel"));
				iv.setOthertel(rs.getString("othertel"));
				iv.setDiseasetype(rs.getString("diseasetype"));
				iv.setPhoto(rs.getString("photo"));
				infoList.add(iv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("病人信息DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return infoList;
	}

	@Override
	public InfoValue getMax() throws Exception {
		InfoValue iv=null;
		String sql="select * from Info where id=(select max(id) from Info) ";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				iv=new InfoValue();
				iv.setId(rs.getInt("id"));
				iv.setName(rs.getString("name"));
				iv.setAge(rs.getInt("age"));
				iv.setTel(rs.getString("tel"));
				iv.setOthertel(rs.getString("othertel"));
				iv.setDiseasetype(rs.getString("diseasetype"));
				iv.setPhoto(rs.getString("photo"));
			
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("病人信息DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return iv;
	}

}
