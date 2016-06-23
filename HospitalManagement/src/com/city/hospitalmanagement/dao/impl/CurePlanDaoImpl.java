package com.city.hospitalmanagement.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.dao.ICurePlanDao;
import com.city.hospitalmanagement.factory.ConnectionFactory;
import com.city.hospitalmanagement.value.CurePlanValue;

public class CurePlanDaoImpl implements ICurePlanDao {

	@Override
	public void create(CurePlanValue cv) throws Exception {
		
		
		String sql="insert into CurePlan(time,event,howoften,details,patientid) values(?,?,?,?,?)";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, cv.getTime());
			ps.setString(2, cv.getEvent());
			ps.setString(3, cv.getHowoften());
			ps.setString(4, cv.getDetails());
			
			ps.setInt(5, cv.getPatientid());
			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("医治计划Dao增加错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
	}

	@Override
	public void update(CurePlanValue cv) throws Exception {
		String sql="update CurePlan set time=?,event=?,howoften=?,details=?,patientid=? where planid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setString(1, cv.getTime());
			ps.setString(2, cv.getEvent());
			ps.setString(3, cv.getHowoften());
			ps.setString(4, cv.getDetails());
			
			ps.setInt(5, cv.getPatientid());
			ps.setInt(6, cv.getPlanid());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("医治计划Dao更新错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void delete(CurePlanValue cv) throws Exception {
		String sql="delete from CurePlan where planid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, cv.getPlanid());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("医治计划Dao删除错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public CurePlanValue get(int id) throws Exception {
		CurePlanValue cv=null;
		String sql="select * from CurePlan where planid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, id);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				cv=new CurePlanValue();
				cv.setPlanid(rs.getInt(1));
				cv.setTime(rs.getString(2));
				cv.setEvent(rs.getString(3));
				cv.setHowoften(rs.getString(4));
				cv.setDetails(rs.getString(5));
				
				cv.setPatientid(rs.getInt(6));
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("医治计划DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return cv;
	}

	@Override
	public List<CurePlanValue> getList() throws Exception {
		List<CurePlanValue> cureplanList=new ArrayList();
		String sql="select * from CurePlan";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				CurePlanValue cv=new CurePlanValue();
				cv.setPlanid(rs.getInt(1));
				cv.setTime(rs.getString(2));
				cv.setEvent(rs.getString(3));
				cv.setHowoften(rs.getString(4));
				cv.setDetails(rs.getString(5));
				
				cv.setPatientid(rs.getInt(6));
				cureplanList.add(cv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("医治计划DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return cureplanList;
	}

	@Override
	public List<CurePlanValue> select(int patientid) throws Exception {
		List<CurePlanValue> cureplanList=new ArrayList();
		String sql="select * from CurePlan where patientid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, patientid);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				CurePlanValue cv=new CurePlanValue();
				cv.setPlanid(rs.getInt(1));
				cv.setTime(rs.getString(2));
				cv.setEvent(rs.getString(3));
				cv.setHowoften(rs.getString(4));
				cv.setDetails(rs.getString(5));
				
				cv.setPatientid(rs.getInt(6));
				cureplanList.add(cv);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("医治计划DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return cureplanList;
	}

}
