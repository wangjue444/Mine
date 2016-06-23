package com.city.hospitalmanagement.factory;

import com.city.hospitalmanagement.business.ICurePlanBusiness;
import com.city.hospitalmanagement.business.IExamBusiness;
import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.business.ILoginBusiness;
import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.business.impl.CurePlanImpl;
import com.city.hospitalmanagement.business.impl.ExamImpl;
import com.city.hospitalmanagement.business.impl.InfoImpl;
import com.city.hospitalmanagement.business.impl.LoginImpl;
import com.city.hospitalmanagement.business.impl.PatientHistoryImpl;

public class BusinessFactory {
	public static ILoginBusiness getLoginBusiness(){
		return new LoginImpl();
	}
	
	public static IInfoBusiness getInfoBusiness(){
		return new InfoImpl();
	}
	
	public static ICurePlanBusiness getCurePlanBusiness(){
		return new CurePlanImpl();
	}
	
	public static IPatientHistoryBusiness getPatientHistoryBusiness(){
		return new PatientHistoryImpl();
	}
	
	public static IExamBusiness getExamBusiness(){
		return new ExamImpl();
	}
}
