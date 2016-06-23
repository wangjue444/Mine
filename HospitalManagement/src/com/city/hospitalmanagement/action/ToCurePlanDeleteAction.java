package com.city.hospitalmanagement.action;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ToCurePlanDeleteAction
 */
@WebServlet("/cureplan/todelete.do")
public class ToCurePlanDeleteAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ToCurePlanDeleteAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setAttribute("planid", request.getParameter("planid"));
		request.setAttribute("time", request.getParameter("time"));
		request.setAttribute("event", request.getParameter("event"));
		request.setAttribute("howoften", request.getParameter("howoften"));
		request.setAttribute("details", request.getParameter("details"));
		request.setAttribute("patientid", request.getParameter("patientid"));
		RequestDispatcher rd=request.getRequestDispatcher("delete.jsp");
		rd.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
