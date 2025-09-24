import React, { useState, useEffect } from 'react';
import { Link, useNavigate, useLocation } from 'react-router-dom'; // Importar useNavigate e useLocation

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

  // Função para rolar suavemente para uma seção, ajustando para o cabeçalho fixo
  const scrollToSection = (id: string) => {
    const element = document.getElementById(id);
    if (element) {
      const headerOffset = 80; // Altura aproximada do cabeçalho fixo
      const elementPosition = element.getBoundingClientRect().top + window.scrollY;
      window.scrollTo({
        top: elementPosition - headerOffset,
        behavior: 'smooth'
      });
    } else {
      console.warn(`Elemento com ID "${id}" não encontrado para rolagem.`);
    }
  };

  // Manipulador de clique para todos os links de navegação
  const handleNavLinkClick = (e: React.MouseEvent<HTMLAnchorElement>, href: string) => {
    e.preventDefault(); // Previne o comportamento padrão do Link/navegador

    if (href === '/') {
      // Para o link 'Início'
      if (location.pathname !== '/') {
        navigate('/'); // Navega para a página inicial se não estiver nela
      }
      window.scrollTo({ top: 0, behavior: 'smooth' }); // Rola para o topo
    } else if (href.startsWith('/#')) {
      // Para links de âncora como '/#diferenciais' ou '/#planos'
      const sectionId = href.substring(2); // Obtém o ID da seção (ex: 'diferenciais')

      if (location.pathname !== '/') {
        // Se não estiver na página inicial, navega para a página inicial com o hash
        navigate(`/${href}`); // Isso fará com que o useEffect abaixo lide com o scroll
      } else {
        // Se já estiver na página inicial, apenas rola para a seção
        scrollToSection(sectionId);
      }
    } else {
      // Para links de rota normais como '/contato'
      navigate(href);
    }
  };

  const navLinks = [
    { name: 'Início', href: '/' },
    { name: 'Sobre', href: '/#diferenciais' }, // Link de âncora para seção na página inicial
    { name: 'Planos', href: '/#planos' },     // Link de âncora para seção na página inicial
    { name: 'Contato', href: '/contato' },    // Rota para a página de Contato
  ];

  // Efeito para rolar para o hash quando o componente é montado ou o hash da URL muda
  // Isso lida com casos onde navegamos de outra página para uma âncora na página inicial
  useEffect(() => {
    if (location.pathname === '/' && location.hash) {
      const id = location.hash.substring(1); // Remove '#'
      // Atraso aumentado para garantir que o elemento alvo esteja renderizado após a mudança de rota
      const timer = setTimeout(() => scrollToSection(id), 300); 
      return () => clearTimeout(timer);
    }
  }, [location.pathname, location.hash]); // Re-executa quando o caminho ou o hash mudam

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
              to={link.href} // Mantém a prop 'to' para acessibilidade e comportamento padrão
              onClick={(e) => handleNavLinkClick(e, link.href)}
              className="text-gray-300 hover:text-orange-500 transition-colors duration-300 font-medium text-sm tracking-wide uppercase"
            >
              {link.name}
            </Link>
          ))}
        </nav>
        {/* Mobile menu button pode ser adicionado aqui */}
      </div>
    </header>
  );
};

export default Header;