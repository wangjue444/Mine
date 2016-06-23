package com.city.hospitalmanagement.action;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.business.ILoginBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;
import com.city.hospitalmanagement.value.InfoValue;
import com.city.hospitalmanagement.value.LoginValue;
import com.jspsmart.upload.SmartUpload;

/**
 * Servlet implementation class PatientAddAction
 */
@WebServlet("/patient/add.do")
public class PatientAddAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
    private ServletConfig config;
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientAddAction() {
        super();
        // TODO Auto-generated constructor stub
    }

    public void init(ServletConfig config) throws ServletException {
		this.config=config;
	}
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			
	
			
			
			
			try {
				
				String contentType=null;
				SmartUpload load=new SmartUpload();
				
				load.initialize(config,request, response);
				load.upload();
				
				
				IInfoBusiness inf=BusinessFactory.getInfoBusiness();
				//String name=new String(load.getRequest().getParameter("name").getBytes("ISO-8859-1"),"UTF-8");
				String name=load.getRequest().getParameter("name");
				
				if(load.getRequest().getParameter("age").trim().equals("")){
					response.sendRedirect("tomain.do");
					return;
				}
					
					
				int age=Integer.parseInt(load.getRequest().getParameter("age"));
				
				String tel=load.getRequest().getParameter("tel");
				String othertel=load.getRequest().getParameter("othertel");
				//String diseasetype=new String(load.getRequest().getParameter("diseasetype").getBytes("ISO-8859-1"),"UTF-8");
				String diseasetype=load.getRequest().getParameter("diseasetype");
				if(name.trim().equals("")||tel.trim().equals("")||othertel.trim().equals("")|diseasetype.trim().equals("")){
					response.sendRedirect("tomain.do");
					return;
				}
				
				
				if(load.getFiles().getFile(0).getSize()>0){
					String filename=load.getFiles().getFile(0).getFileName();
					contentType=load.getFiles().getFile(0).getContentType();
					
					load.getFiles().getFile(0).saveAs("/upload/"+filename);
					String realpath=request.getSession().getServletContext().getRealPath("/upload/"+filename);
				
					
					inf.add(name, age, tel, othertel, diseasetype,realpath);
					InfoValue latest=inf.getMax();
					
					ILoginBusiness ilb=BusinessFactory.getLoginBusiness();
					ilb.add(latest.getId()+"", "patient", "p");
				}
				
				
				
				response.sendRedirect("tomain.do");
				
				
			} catch (Exception e) {
				e.printStackTrace();
			}
			
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
