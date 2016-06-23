package com.city.hospitalmanagement.factory;

import com.city.hospitalmanagement.dao.ICurePlanDao;
import com.city.hospitalmanagement.dao.IExamDao;

import com.city.hospitalmanagement.dao.IInfoDao;
import com.city.hospitalmanagement.dao.ILoginDao;
import com.city.hospitalmanagement.dao.IPatientHistoryDao;
import com.city.hospitalmanagement.dao.impl.CurePlanDaoImpl;
import com.city.hospitalmanagement.dao.impl.ExamDaoImpl;

import com.city.hospitalmanagement.dao.impl.InfoDaoImpl;
import com.city.hospitalmanagement.dao.impl.LoginDaoImpl;
import com.city.hospitalmanagement.dao.impl.PatientHistoryDaoImpl;

public class DaoFactory {
	public static ICurePlanDao getCurePlanDao(){
		return new CurePlanDaoImpl();
	}
	
	public static IExamDao getExamDao(){
		return new ExamDaoImpl();
	}
	

	
	public static IInfoDao getInfoDao(){
		return new InfoDaoImpl();
	}
	
	public static ILoginDao getLoginDao(){
		return new LoginDaoImpl();
	}
	
	public static IPatientHistoryDao getPatientHistoryDao(){
		return new PatientHistoryDaoImpl();
	}
}
