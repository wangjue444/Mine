package com.city.hospitalmanagement.action;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.business.ILoginBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class PatientDeleteAction
 */
@WebServlet("/patient/delete.do")
public class PatientDeleteAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientDeleteAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try {
			int id=Integer.parseInt(request.getParameter("id"));
			IInfoBusiness inf=BusinessFactory.getInfoBusiness();
			inf.delete(id);
			ILoginBusiness ilb=BusinessFactory.getLoginBusiness();
			ilb.delete(id+"");
			response.sendRedirect("tomain.do");
			return;
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
