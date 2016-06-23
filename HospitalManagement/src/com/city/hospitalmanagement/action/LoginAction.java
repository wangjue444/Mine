package com.city.hospitalmanagement.action;

import java.io.IOException;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.city.hospitalmanagement.business.ILoginBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class LoginAction
 */
@WebServlet("/login.do")
public class LoginAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request,response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		String type=request.getParameter("type");
		if(username==null||password==null||type==null){
			response.sendRedirect("login.jsp");
			return;
		}
		String ttype=null;
		if(type.equals("admin")){
			ttype="a";
		}
		else if(type.equals("patient")){
			ttype="p";
		}
		
	
		
		ILoginBusiness lgn=BusinessFactory.getLoginBusiness();
		try{
			boolean isRight=lgn.check(username, password, ttype);
			
			if(isRight){
				HttpSession session=request.getSession();
				
				
				session.setAttribute("username", username);
				session.setAttribute("type", type);
				
				RequestDispatcher rd=request.getRequestDispatcher("tomain.do");
				rd.forward(request, response);
			}
			else{
				response.sendRedirect("login.jsp");
				return;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			String mess=e.getMessage();
			response.sendRedirect("error.jsp?mess="+mess);
		}
	}

}
