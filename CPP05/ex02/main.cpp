/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:37 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/18 15:26:29 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    std::cout << "\n===== 관료와 폼 객체 생성 =====\n" << std::endl;
    
    Bureaucrat highRank("Director", 1);
    Bureaucrat lowRank("Intern", 140);
    
    std::cout << "생성된 관료들:" << std::endl;
    std::cout << highRank << std::endl;
    std::cout << lowRank << std::endl;

    AForm* forms[3];
    forms[0] = new ShrubberyCreationForm("Garden");
    forms[1] = new RobotomyRequestForm("Claptrap");
    forms[2] = new PresidentialPardonForm("Criminal");
    
    std::cout << "\n생성된 폼들:" << std::endl;
    std::cout << "폼 1: " << *forms[0] << std::endl;
    std::cout << "폼 2: " << *forms[1] << std::endl;
    std::cout << "폼 3: " << *forms[2] << std::endl;
    
    std::cout << "\n===== 폼 서명 테스트 =====\n" << std::endl;
    
    std::cout << "높은 등급 관료 서명 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        highRank.signForm(*forms[i]);
    }
    std::cout << "\n낮은 등급 관료 서명 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        lowRank.signForm(*forms[i]);
    }
    
    std::cout << "\n===== 폼 실행 테스트 =====\n" << std::endl;

    std::cout << "높은 등급 관료 실행 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        try {
            std::cout << "폼 " << i+1 << " 실행 시도: ";
            highRank.executeForm(*forms[i]);
        } catch (std::exception& e) {
            std::cerr << "예외 발생: " << e.what() << std::endl;
        } catch (const char* e) {
            std::cerr << "예외 발생: " << e << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\n낮은 등급 관료 실행 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        try {
            std::cout << "폼 " << i+1 << " 실행 시도: ";
            lowRank.executeForm(*forms[i]);
        } catch (std::exception& e) {
            std::cerr << "예외 발생: " << e.what() << std::endl;
        } catch (const char* e) {
            std::cerr << "예외 발생: " << e << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\n===== 미서명 폼 테스트 =====\n" << std::endl;

    AForm* unsignedForm = new PresidentialPardonForm("Innocent");
    std::cout << "미서명 폼: " << *unsignedForm << std::endl;
    
    try {
        std::cout << "미서명 폼 실행 시도: ";
        highRank.executeForm(*unsignedForm);
    } catch (std::exception& e) {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
    std::cout << "\n===== 메모리 정리 =====\n" << std::endl;
    for (int i = 0; i < 3; i++) {
        delete forms[i];
    }
    delete unsignedForm;
    
    std::cout << "프로그램 종료" << std::endl;
    
    return 0;
}