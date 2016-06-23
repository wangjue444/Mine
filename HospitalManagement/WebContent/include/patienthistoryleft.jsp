<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
  <div class="row">
      <div class="span3 bs-docs-sidebar">
	<h1></h1>
	<form class="form-horizontal well" action="../logout.do">
					 
					用户名:${username}<br/>
					 
				 	  

				
					  用户类型:${type}<br/>
					
					  
					
				        <button class="btn btn-warning" type="submit">注销</button>
					
									
					</form>
<h1></h1>

        <ul class="nav nav-list bs-docs-sidenav">
          <li><a href="tomain.do"><i class="icon-chevron-right"></i>病史管理</a></li>
          <c:if test="${type=='admin'}">
          <li><a href="toadd.do"><i class="icon-chevron-right"></i>增加病史</a></li>
          <li><a onclick="OnDelete()"><i class="icon-chevron-right"></i>删除病史</a></li>
          <li><a onclick="OnUpdate()"><i class="icon-chevron-right"></i>修改病史</a></li>
          <li><a href="toselect.do"><i class="icon-chevron-right"></i>查询病史</a></li>
          </c:if>
           <li><a href="../main.jsp"><i class="icon-chevron-right"></i>返回主菜单</a></li>
          
         
        </ul>


	       	
	<h1></h1>			
     
   </div>