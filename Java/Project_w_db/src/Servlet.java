/**
 * Created by udichje on 5/7/17.
 */

import javax.servlet.*;
import javax.servlet.http.*;

import java.io.*;
import java.sql.*;
import java.util.*;
import java.net.*;

public class Servlet extends HttpServlet{

    StockDatabase database;

    public void init() throws ServletException{
        try {
            database = new StockDatabase();
        } catch (SQLException e) {
            System.out.println("Servlet : SQL Exception creating new DB " +
                    "object.");
            e.printStackTrace();
            System.exit(1);
        } catch (ClassNotFoundException e){
            System.out.println("Servlet : Class NotFoundException creating " +
                    "new DB object");
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void destroy(){
        try
        {
            database.close();
        }
        catch (IOException e) {
            System.out.println("IOException closing database:");
            e.printStackTrace();
            System.exit(1);
        }
        catch (SQLException e) {
            System.out.println("SQLException closing database:");
            e.printStackTrace();
            System.exit(1);
        }
        catch (ClassNotFoundException e) {
            System.out.println("ClassNotFoundException closing database:");
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void doGet(HttpServletRequest request, HttpServletResponse
            response) throws ServletException, IOException{
        doPost(request, response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse
            response) throws ServletException, IOException{
        User user = null;
        String userID;
        String password;
        boolean validAction = true;

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();

        response.setHeader("Expires", "Tues, 01 Jan 1980 00:00:00 GMT");

        HttpSession session = request.getSession(true);

    }
}