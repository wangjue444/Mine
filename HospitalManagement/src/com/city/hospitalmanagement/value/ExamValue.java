package com.city.hospitalmanagement.value;

public class ExamValue {
	private int id;
	private int patientid;
	private String time;
	private int breath;
	private int pluse;
	private double temperature;
	private int bloodpressure;

	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getPatientid() {
		return patientid;
	}
	public void setPatientid(int patientid) {
		this.patientid = patientid;
	}
	public String getTime() {
		return time;
	}
	public void setTime(String time) {
		this.time = time;
	}
	public int getBreath() {
		return breath;
	}
	public void setBreath(int breath) {
		this.breath = breath;
	}
	public int getPluse() {
		return pluse;
	}
	public void setPluse(int pluse) {
		this.pluse = pluse;
	}
	public double getTemperature() {
		return temperature;
	}
	public void setTemperature(double temperature) {
		this.temperature = temperature;
	}
	public int getBloodpressure() {
		return bloodpressure;
	}
	public void setBloodpressure(int bloodpressure) {
		this.bloodpressure = bloodpressure;
	}

	
}
