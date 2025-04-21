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

// int main(void)
// {
// {
//     std::cout<<"----------------------------------------------------------"<<std::endl;
//     Bureaucrat test3("test3", 1);
//     Bureaucrat test4("test4", 140);
//     AForm *pol[3];
//     pol[0] = new ShrubberyCreationForm("Shrubbery");
//     pol[1] = new RobotomyRequestForm("Robot");
//     pol[2] = new PresidentialPardonForm("Pardon");
//     srand(getpid());
//     try
//     {
//         int random = rand() % 3;
//         test3.signForm(*pol[random]);
//         test3.executeForm(*pol[random]);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     catch(const char *e)
//     {
//         std::cerr << e << '\n';
//     }
//     for (int i = 0; i < 3; i++)
//         delete pol[i];
//     return (0);
// }
// }

int main(void)
{
    std::cout << "\n===== 관료와 폼 객체 생성 =====\n" << std::endl;
    
    // 두 개의 다른 등급을 가진 관료 생성
    Bureaucrat highRank("Director", 1);    // 최고 등급(1)
    Bureaucrat lowRank("Intern", 140);     // 낮은 등급(140)
    
    std::cout << "생성된 관료들:" << std::endl;
    std::cout << highRank << std::endl;    // 연산자 오버로딩 출력
    std::cout << lowRank << std::endl;
    
    // 세 가지 유형의 폼 생성
    AForm* forms[3];
    forms[0] = new ShrubberyCreationForm("Garden");
    forms[1] = new RobotomyRequestForm("Claptrap");
    forms[2] = new PresidentialPardonForm("Criminal");
    
    std::cout << "\n생성된 폼들:" << std::endl;
    std::cout << "폼 1: " << *forms[0] << std::endl;
    std::cout << "폼 2: " << *forms[1] << std::endl;
    std::cout << "폼 3: " << *forms[2] << std::endl;
    
    std::cout << "\n===== 폼 서명 테스트 =====\n" << std::endl;
    
    // 높은 등급 관료가 모든 폼에 서명 시도
    std::cout << "높은 등급 관료 서명 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        highRank.signForm(*forms[i]);
    }
    
    // 낮은 등급 관료가 모든 폼에 서명 시도
    std::cout << "\n낮은 등급 관료 서명 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        lowRank.signForm(*forms[i]);  // 일부 폼은 등급이 너무 낮아 서명 실패
    }
    
    std::cout << "\n===== 폼 실행 테스트 =====\n" << std::endl;
    
    // 높은 등급 관료가 모든 폼 실행 시도
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
    
    // 낮은 등급 관료가 모든 폼 실행 시도
    std::cout << "\n낮은 등급 관료 실행 시도:" << std::endl;
    for (int i = 0; i < 3; i++) {
        try {
            std::cout << "폼 " << i+1 << " 실행 시도: ";
            lowRank.executeForm(*forms[i]);  // 대부분 등급이 너무 낮아 실행 실패
        } catch (std::exception& e) {
            std::cerr << "예외 발생: " << e.what() << std::endl;
        } catch (const char* e) {
            std::cerr << "예외 발생: " << e << std::endl;
        }
        std::cout << std::endl;
    }
    
    // 미서명 폼 테스트
    std::cout << "\n===== 미서명 폼 테스트 =====\n" << std::endl;
    
    // 새 폼 생성 (서명되지 않은 상태)
    AForm* unsignedForm = new PresidentialPardonForm("Innocent");
    std::cout << "미서명 폼: " << *unsignedForm << std::endl;
    
    try {
        std::cout << "미서명 폼 실행 시도: ";
        highRank.executeForm(*unsignedForm);  // 서명되지 않아 실행 실패
    } catch (std::exception& e) {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
    
    // 메모리 해제
    std::cout << "\n===== 메모리 정리 =====\n" << std::endl;
    for (int i = 0; i < 3; i++) {
        delete forms[i];
    }
    delete unsignedForm;
    
    std::cout << "프로그램 종료" << std::endl;
    
    return 0;
}