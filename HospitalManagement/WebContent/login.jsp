<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html><head>
  
  <meta content="text/html; charset=utf-8" http-equiv="content-type">
  <title>First</title>

  
  
 
	 <link rel="stylesheet" href="assets/css/bootstrap.css" type="text/css">
</head><body>
<div id="login_header_wrapper">
<div id="login_header">

</div>
</div>
<fmt:setBundle basename="loginText"/>
<div class="well span4 offset6" id="content">
 <form action="login.do" method="post" class="form-signin" >
        <h2 class="form-signin-heading"><fmt:message key="title"/></h2>
        <input type="text" class="input-block-level"    name="username"  placeholder="<fmt:message key="username"/>"/>
        <input type="password" class="input-block-level"   name="password"  placeholder="<fmt:message key="password"/>" />
       
        <button class="btn btn-large btn-primary" type="submit"><fmt:message key="login"/></button>
		<input type="radio" name="type" value="admin"/><fmt:message key="admin"/><input type="radio" name="type" value="patient"/><fmt:message key="patient"/>
      </form>
</div>



</body></html>