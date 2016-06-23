package com.city.hospitalmanagement.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.dao.IExamDao;
import com.city.hospitalmanagement.factory.ConnectionFactory;
import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.ExamValue;

public class ExamDaoImpl implements IExamDao {

	@Override
	public void create(ExamValue ev) throws Exception {

		String sql="insert into Exam(patientid,time,breath,pluse,temperature,bloodpressure) values(?,?,?,?,?,?)";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, ev.getPatientid());
			ps.setString(2, ev.getTime());
			ps.setInt(3, ev.getBreath());
			ps.setInt(4, ev.getPluse());
			ps.setDouble(5, ev.getTemperature());
			ps.setInt(6, ev.getBloodpressure());
		
			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("体检Dao增加错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void update(ExamValue ev) throws Exception {
String sql="update Exam set patientid=?,time=?,breath=?,pluse=?,temperature=?,bloodpressure=? where id=?";
		
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, ev.getPatientid());
			ps.setString(2, ev.getTime());
			ps.setInt(3, ev.getBreath());
			ps.setInt(4, ev.getPluse());
			ps.setDouble(5, ev.getTemperature());
			ps.setInt(6, ev.getBloodpressure());
			
			ps.setInt(7, ev.getId());
			ps.execute();
			ps.close();
			
			
		}
		
		catch(Exception e){
			throw new Exception("体检Dao更新错误"+e.getMessage());
		}
		finally{
			cn.close();
		}

	}

	@Override
	public void delete(ExamValue ev) throws Exception {
		String sql="delete from Exam where id=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, ev.getId());
			ps.execute();
			ps.close();
			
		}
		catch(Exception e){
			throw new Exception("体检Dao删除错误"+e.getMessage());
		}
		finally{
			cn.close();
		}


	}

	@Override
	public ExamValue get(int id) throws Exception {
		ExamValue ev=null;
		String sql="select * from Exam where id=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, id);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				ev=new ExamValue();
				ev.setId(rs.getInt(1));
				ev.setPatientid(rs.getInt(2));
				ev.setTime(rs.getString(3));
				ev.setBreath(rs.getInt(4));
				ev.setPluse(rs.getInt(5));
				ev.setTemperature(rs.getDouble(6));
				ev.setBloodpressure(rs.getInt(7));
				
			}
			
			rs.close();
			ps.close();
			
		}catch(Exception e){
			throw new Exception("体检DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		
		return ev;
	}

	@Override
	public List<ExamValue> getList() throws Exception {
		List<ExamValue> examList=new ArrayList();
		String sql="select * from Exam";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				ExamValue ev=new ExamValue();
				ev.setId(rs.getInt(1));
				ev.setPatientid(rs.getInt(2));
				ev.setTime(rs.getString(3));
				ev.setBreath(rs.getInt(4));
				ev.setPluse(rs.getInt(5));
				ev.setTemperature(rs.getDouble(6));
				ev.setBloodpressure(rs.getInt(7));
				
				examList.add(ev);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("体检DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return examList;
	}

	@Override
	public List<ExamValue> select(int patientid) throws Exception {
		List<ExamValue> examList=new ArrayList();
		String sql="select * from Exam where patientid=?";
		Connection cn=null;
		try{
			cn=ConnectionFactory.getConnection();
			PreparedStatement ps=cn.prepareStatement(sql);
			ps.setInt(1, patientid);
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				ExamValue ev=new ExamValue();
				ev.setId(rs.getInt(1));
				ev.setPatientid(rs.getInt(2));
				ev.setTime(rs.getString(3));
				ev.setBreath(rs.getInt(4));
				ev.setPluse(rs.getInt(5));
				ev.setTemperature(rs.getDouble(6));
				ev.setBloodpressure(rs.getInt(7));
				
				examList.add(ev);
				
			}
			rs.close();
			ps.close();
		}
		catch(Exception e){
			throw new Exception("体检DAO查询错误"+e.getMessage());
		}
		finally{
			cn.close();
		}
		return examList;
	}

}
