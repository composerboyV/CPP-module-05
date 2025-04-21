/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:30:12 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/21 14:30:12 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

// 구분선 출력 함수
void printSeparator()
{
    std::cout << "\n--------------------------------------------------\n" << std::endl;
}

int main(void)
{
    std::cout << "TESTING INTERN CLASS" << std::endl;
    printSeparator();

    // 인턴 생성
    Intern someRandomIntern;
    
    // 다양한 등급의 관료 생성
    Bureaucrat boss("Boss", 1);         // 최고 등급
    Bureaucrat manager("Manager", 25);  // 중간 등급
    Bureaucrat worker("Worker", 70);    // 낮은 등급
    Bureaucrat intern("Intern", 140);   // 최하위 등급
    
    // 1. 모든 폼 유형 테스트
    {
        std::cout << "1. TESTING ALL FORM TYPES:" << std::endl;
        
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery", "Garden");
        AForm* robotForm = someRandomIntern.makeForm("RobotRequest", "Bender");
        AForm* pardonForm = someRandomIntern.makeForm("Presidnet", "Arthur Dent");
        
        if (shrubForm) {
            std::cout << "\nShrubbery Form Info: " << *shrubForm << std::endl;
            boss.signForm(*shrubForm);
            boss.executeForm(*shrubForm);
            delete shrubForm;
        }
        
        if (robotForm) {
            std::cout << "\nRobotomy Form Info: " << *robotForm << std::endl;
            boss.signForm(*robotForm);
            boss.executeForm(*robotForm);
            delete robotForm;
        }
        
        if (pardonForm) {
            std::cout << "\nPresidential Pardon Form Info: " << *pardonForm << std::endl;
            boss.signForm(*pardonForm);
            boss.executeForm(*pardonForm);
            delete pardonForm;
        }
    }
    printSeparator();
    
    // 2. 존재하지 않는 폼 테스트
    {
        std::cout << "2. TESTING NON-EXISTENT FORM:" << std::endl;
        
        AForm* nonExistentForm = someRandomIntern.makeForm("Non-existent Form", "Nobody");
        
        if (nonExistentForm) {
            boss.signForm(*nonExistentForm);
            boss.executeForm(*nonExistentForm);
            delete nonExistentForm;
        } else {
            std::cout << "Form was not created, as expected." << std::endl;
        }
    }
    printSeparator();
    
    // 3. 다양한 등급의 관료가 폼을 처리하는 테스트
    {
        std::cout << "3. TESTING DIFFERENT BUREAUCRAT GRADES:" << std::endl;
        
        // 대통령 사면 양식 (서명: 25, 실행: 5)
        AForm* pardonForm = someRandomIntern.makeForm("Presidnet", "Ford Prefect");
        
        if (pardonForm) {
            std::cout << "\nForm requires sign grade " << pardonForm->getSigngrade() 
                      << " and execute grade " << pardonForm->getplaygrade() << std::endl;
            
            std::cout << "\nAttempting with Manager (grade 25):" << std::endl;
            manager.signForm(*pardonForm);
            manager.executeForm(*pardonForm);  // 서명은 가능하지만 실행 불가
            
            std::cout << "\nAttempting with Boss (grade 1):" << std::endl;
            boss.executeForm(*pardonForm);  // 실행 가능
            
            delete pardonForm;
        }
    }
    printSeparator();
    
    // 4. 랜덤 폼 생성 및 처리 테스트
    {
        std::cout << "4. TESTING RANDOM FORM CREATION:" << std::endl;
        
        srand(getpid());  // 시드 설정
        
        std::string formTypes[4];
        formTypes[0] = "shrubbery";
        formTypes[1] = "RobotRequest";
        formTypes[2] = "Presidnet";
        formTypes[3] = "Invalid Form";
        
        int random = rand() % 4;
        std::cout << "Randomly selected form type: " << formTypes[random] << std::endl;
        
        AForm* randomForm = someRandomIntern.makeForm(formTypes[random], "Random Target");
        
        if (randomForm) {
            std::cout << "\nForm Info: " << *randomForm << std::endl;
            boss.signForm(*randomForm);
            boss.executeForm(*randomForm);
            delete randomForm;
        } else {
            std::cout << "Random form was not created." << std::endl;
        }
    }
    
    printSeparator();
    std::cout << "ALL TESTS COMPLETED" << std::endl;
    
    return 0;
}