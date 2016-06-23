package com.city.hospitalmanagement.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.dao.IPatientHistoryDao;
import com.city.hospitalmanagement.factory.ConnectionFactory;
import com.city.hospitalmanagement.value.LoginValue;
import com.city.hospitalmanagement.value.PatientHistoryValue;

public class PatientHistoryDaoImpl implements IPatientHistoryDao{

	@Override
	public void create(PatientHistoryValue pv) throws Exception {
		String sql="insert into PatientHistory(content,patientid) values(?,?)";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, pv.getContent());
			ps.setInt(2, pv.getPatientid());

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("病史Dao增加错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
	}

	@Override
	public void delete(PatientHistoryValue pv) throws Exception {
		String sql="delete from PatientHistory where id=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1,pv.getId());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("病史Dao删除错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
	}

	@Override
	public void update(PatientHistoryValue pv) throws Exception {
		String sql="update PatientHistory set content=?,patientid=? where id=?";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, pv.getContent());
			ps.setInt(2, pv.getPatientid());
			ps.setInt(3, pv.getId());

			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("病史Dao更新错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
	}

	@Override
	public PatientHistoryValue get(int id) throws Exception {
		PatientHistoryValue pv=null;
		String sql="select * from PatientHistory where id=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, id);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				pv=new PatientHistoryValue();
				pv.setId(rs.getInt(1));
				pv.setContent(rs.getString(2));
				pv.setPatientid(rs.getInt(3));
		
			
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("病史DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return pv;
	}

	@Override
	public List<PatientHistoryValue> getList() throws Exception {
		List<PatientHistoryValue> patienthistoryList=new ArrayList();
		String sql="select * from PatientHistory";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				PatientHistoryValue lv=new PatientHistoryValue();
				PatientHistoryValue pv=new PatientHistoryValue();
				pv.setId(rs.getInt(1));
				pv.setContent(rs.getString(2));
				pv.setPatientid(rs.getInt(3));
			
				patienthistoryList.add(pv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("病史DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return patienthistoryList;
	}

	@Override
	public List<PatientHistoryValue> select(int patientid) throws Exception {
		List<PatientHistoryValue> patienthistoryList=new ArrayList();
		String sql="select * from PatientHistory where patientid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, patientid);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				PatientHistoryValue lv=new PatientHistoryValue();
				PatientHistoryValue pv=new PatientHistoryValue();
				pv.setId(rs.getInt(1));
				pv.setContent(rs.getString(2));
				pv.setPatientid(rs.getInt(3));
			
				patienthistoryList.add(pv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("病史DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return patienthistoryList;
		
	}

}
