/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:57:01 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/27 19:14:38 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int main()
{
    try
    {
        // 정상적인 범위의 관료 생성
        Bureaucrat normal("김철수", 75);
        std::cout << normal.getName() << ", 등급: " << normal.getGrade() << std::endl;
        
        // 등급 올리기/내리기 테스트
        normal.incrementGrade();
        std::cout << "등급 상승 후: " << normal.getGrade() << std::endl;
        
        normal.decrementGrade();
        std::cout << "등급 하락 후: " << normal.getGrade() << std::endl;
        
        // 예외 발생 테스트: 등급이 너무 높은 경우
        Bureaucrat tooHigh("이영희", 0);  // 1보다 작은 등급 (에러 발생)
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << "등급이 너무 높음 오류: " << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << "등급이 너무 낮음 오류: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
    
    // 범위를 벗어나는 등급으로 관료 생성 시도
    try
    {
        Bureaucrat tooLow("박민수", 151);  // 150보다 큰 등급 (에러 발생)
    }
    catch (const std::exception& e)
    {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
    
    return 0;
}
// int	main()
// {
// 	try
// 	{
// 		Bureaucrat	test1("dog", 150);
// 		std::cout << test1.getName() << "등급 : " << test1.getGrade() << std::endl;		
// 		test1.incrementGrade();
// 		std::cout << "등급상승" << test1.getGrade() << std::endl;
// 		test1.decrementGrade();
// 		std::cout << "등급하락" << test1.getGrade() << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{    // 예외가 발생했다면 동작해야하는 코드들
// 		std::cerr << e.what() << '\n';
// 	}
// 	// try - catch 문이 정상적으로 동작했다면 실행되어야 하는 코드들
// 	return (0);
// }