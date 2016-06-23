package com.city.hospitalmanagement.action;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.ICurePlanBusiness;
import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;
import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.InfoValue;

/**
 * Servlet implementation class ToCurePlanMainAction
 */
@WebServlet("/cureplan/tomain.do")
public class ToCurePlanMainAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ToCurePlanMainAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ICurePlanBusiness cpb=BusinessFactory.getCurePlanBusiness();
		try{
			List<CurePlanValue> list=cpb.getList();
			
			request.setAttribute("list", list);
			
			
			RequestDispatcher rd=request.getRequestDispatcher("main.jsp");
			rd.forward(request, response);
			
		}
		catch(Exception e){
			e.printStackTrace();
			String mess=e.getMessage();
			response.sendRedirect("../error.jsp?mess="+mess);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
