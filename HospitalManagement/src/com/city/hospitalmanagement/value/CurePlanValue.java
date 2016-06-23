package com.city.hospitalmanagement.value;

public class CurePlanValue {
	private int planid;
	private String time;
	private String event;
	private String howoften;
	private String details;
	
	private int patientid;
	
	public int getPlanid() {
		return planid;
	}
	public void setPlanid(int planid) {
		this.planid = planid;
	}
	public String getTime() {
		return time;
	}
	public void setTime(String time) {
		this.time = time;
	}
	public String getEvent() {
		return event;
	}
	public void setEvent(String event) {
		this.event = event;
	}
	public String getHowoften() {
		return howoften;
	}
	public void setHowoften(String howoften) {
		this.howoften = howoften;
	}
	public String getDetails() {
		return details;
	}
	public void setDetails(String details) {
		this.details = details;
	}
	
	public int getPatientid() {
		return patientid;
	}
	public void setPatientid(int patientid) {
		this.patientid = patientid;
	}
	

}
