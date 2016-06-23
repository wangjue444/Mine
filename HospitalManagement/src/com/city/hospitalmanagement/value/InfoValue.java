package com.city.hospitalmanagement.value;

public class InfoValue {
	private int id;
    private String name;
    private int age;
    private String tel;
    private String othertel;
    private String diseasetype;
    private String photo;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getTel() {
		return tel;
	}
	public void setTel(String tel) {
		this.tel = tel;
	}
	public String getOthertel() {
		return othertel;
	}
	public void setOthertel(String othertel) {
		this.othertel = othertel;
	}
	public String getDiseasetype() {
		return diseasetype;
	}
	public void setDiseasetype(String diseasetype) {
		this.diseasetype = diseasetype;
	}
	
	public void setPhoto(String photo){
		this.photo=photo;
	}
	public String getPhoto(){
		return photo;
	}
}
