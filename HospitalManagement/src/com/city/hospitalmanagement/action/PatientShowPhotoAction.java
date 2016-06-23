package com.city.hospitalmanagement.action;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;
import com.city.hospitalmanagement.value.InfoValue;

/**
 * Servlet implementation class PatientShowPhotoAction
 */
@WebServlet("/patient/showphoto.do")
public class PatientShowPhotoAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientShowPhotoAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try {
			int len=0;
			int id=Integer.parseInt(request.getParameter("id"));
			IInfoBusiness inf=BusinessFactory.getInfoBusiness();
			InfoValue iv=inf.get(id);
			byte[] data=new byte[3000];
			response.setContentType("image/jpeg");
			OutputStream out=response.getOutputStream();
			File f = new File(iv.getPhoto());
			InputStream in=new FileInputStream(f);
			while((len=in.read(data))!=-1){
				out.write(data,0,len);
			}
			in.close();
			out.close();
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
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
