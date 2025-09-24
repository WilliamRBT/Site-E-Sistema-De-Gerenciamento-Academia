import React, { useState, useEffect } from 'react';
import { Link, useNavigate, useLocation } from 'react-router-dom';

const Header: React.FC = () => {
  const [isScrolled, setIsScrolled] = useState(false);
  const navigate = useNavigate();
  const location = useLocation();

  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 10);
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  const scrollToSection = (id: string) => {
    const element = document.getElementById(id);
    if (element) {
      const headerOffset = 80;
      const elementPosition = element.getBoundingClientRect().top + window.scrollY;
      window.scrollTo({
        top: elementPosition - headerOffset,
        behavior: 'smooth'
      });
    }
  };

  const handleNavLinkClick = (e: React.MouseEvent<HTMLAnchorElement>, href: string) => {
    e.preventDefault();

    if (href === '/') {
      if (location.pathname !== '/') {
        navigate('/');
      }
      window.scrollTo({ top: 0, behavior: 'smooth' });
    } else if (href.startsWith('/#')) {
      const sectionId = href.substring(2);

      if (location.pathname !== '/') {
        // CORREÇÃO AQUI: Navega para a rota raiz com o hash correto
        navigate(`/${href}`); 
      } else {
        scrollToSection(sectionId);
      }
    } else {
      navigate(href);
    }
  };

  const navLinks = [
    { name: 'Início', href: '/' },
    { name: 'Sobre', href: '/#diferenciais' },
    { name: 'Planos', href: '/#planos' },
    { name: 'Contato', href: '/contato' },
  ];

  useEffect(() => {
    if (location.pathname === '/' && location.hash) {
      const id = location.hash.substring(1);
      const timer = setTimeout(() => scrollToSection(id), 100); 
      return () => clearTimeout(timer);
    }
  }, [location.pathname, location.hash]);

  return (
    <header className={`fixed top-0 left-0 right-0 z-50 transition-all duration-300 ${isScrolled ? 'bg-black/50 shadow-lg backdrop-blur-md border-b border-gray-800' : 'bg-transparent'}`}>
      <div className="container mx-auto px-6 py-4 flex justify-between items-center">
        <Link to="/" className="text-2xl font-bold tracking-wider text-white" onClick={(e) => handleNavLinkClick(e, '/')}>
          GYM <span className="text-orange-500">ELITE</span>
        </Link>
        <nav className="hidden md:flex space-x-8">
          {navLinks.map((link) => (
            <Link
              key={link.name}
              to={link.href}
              onClick={(e) => handleNavLinkClick(e, link.href)}
              className="text-gray-300 hover:text-orange-500 transition-colors duration-300 font-medium text-sm tracking-wide uppercase"
            >
              {link.name}
            </Link>
          ))}
        </nav>
      </div>
    </header>
  );
};

export default Header;