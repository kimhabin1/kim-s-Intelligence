package idusw.sba.sba202312001.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class HomeController {
    @GetMapping("/")
    public String goHome() {
        return "index";
    }
    @GetMapping("/charts")
    public String goCharts() {
        return "charts";
    }
    @GetMapping("/login")
    public String goLogin() {
        return "login";
    }
    @GetMapping("/logout")
    public String goLogout() {
        return "logout";
    }
}
